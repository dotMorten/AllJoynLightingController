using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Foundation.Collections;

namespace LightingControllerService.Client
{
    public class ObservableDictionary<TKey, TValue> : IObservableMap<TKey, TValue>
    {
        private Windows.UI.Core.CoreDispatcher dispatcher;
        private object syncRoot = new object();

        private readonly IDictionary<TKey, TValue> dictionary;

        #region Constructors
        public ObservableDictionary(Windows.UI.Core.CoreDispatcher dispatcher)
        {
            this.dispatcher = dispatcher;
            dictionary = new Dictionary<TKey, TValue>();
        }

        public event MapChangedEventHandler<TKey, TValue> MapChanged;
        #endregion

        #region IDictionary<TKey,TValue> Members

        public void Add(TKey key, TValue value)
        {
            lock(syncRoot)
            {
                dictionary.Add(key, value);
            }
            OnItemInserted(key);
        }

        public bool ContainsKey(TKey key)
        {
            lock(syncRoot)
                return dictionary.ContainsKey(key);
        }

        public ICollection<TKey> Keys
        {
            get
            {
                lock (syncRoot)
                    return new Collection<TKey>(dictionary.Keys.ToArray());
            }
        }

        public bool Remove(TKey key)
        {
            if (key == null) throw new ArgumentNullException("key");

            bool removed = false;
            lock (syncRoot)
                removed = dictionary.Remove(key);
            if (removed)
                OnItemRemoved(key);
            return removed;
        }


        public bool TryGetValue(TKey key, out TValue value)
        {
            lock (syncRoot)
                return dictionary.TryGetValue(key, out value);
        }

        public ICollection<TValue> Values
        {
            get
            {
                lock (syncRoot)
                    return new Collection<TValue>(dictionary.Values.ToArray());
            }
        }


        public TValue this[TKey key]
        {
            get
            {
                lock (syncRoot)
                    return dictionary[key];
            }
            set
            {
                bool isReplace = false;
                lock (syncRoot)
                {
                    isReplace = dictionary.ContainsKey(key);
                    dictionary[key] = value;
                }
                if(isReplace)
                    OnItemReplaced(key);
                else
                    OnItemInserted(key);
            }
        }


        #endregion


        #region ICollection<KeyValuePair<TKey,TValue>> Members


        public void Add(KeyValuePair<TKey, TValue> item)
        {
            Add(item.Key, item.Value);
        }
        
        public void Clear()
        {
            int count = 0;
            lock (syncRoot)
            {
                count = dictionary.Count;
                if (count > 0)
                    dictionary.Clear();
            }
            if (count > 0)
            {
                OnCollectionChanged();
            }
        }

        public bool Contains(KeyValuePair<TKey, TValue> item)
        {
            lock (syncRoot)
                return dictionary.Contains(item);
        }
        
        public void CopyTo(KeyValuePair<TKey, TValue>[] array, int arrayIndex)
        {
            lock (syncRoot)
                dictionary.CopyTo(array, arrayIndex);
        }
        
        public int Count
        {
            get
            {
                lock (syncRoot)
                    return dictionary.Count;
            }
        }
        
        public bool IsReadOnly
        {
            get { return dictionary.IsReadOnly; }
        }

        public bool Remove(KeyValuePair<TKey, TValue> item)
        {
            return Remove(item.Key);
        }
        
        #endregion
        
        #region IEnumerable<KeyValuePair<TKey,TValue>> Members
        
        public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator()
        {
            return dictionary.GetEnumerator();
        }
        
        #endregion
        
        #region IEnumerable Members
        
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
        
        #endregion

        public void AddRange(IDictionary<TKey, TValue> items)
        {
            if (items == null) throw new ArgumentNullException("items");

            if (items.Any())
            {
                int count = dictionary.Count;
                lock(syncRoot)
                {
                    foreach (var item in items)
                    {
                        dictionary.Add(item);
                        OnItemInserted(item.Key);
                    }
                }
                //OnCollectionChanged();
                //OnItemInserted(items.ToList(), count);
            }
        }

        private void OnCollectionChanged()
        {
            if (dispatcher.HasThreadAccess)
            {
                MapChanged?.Invoke(this, new MapChangedEventArgs<TKey>(default(TKey), CollectionChange.Reset));
            }
            else
            {
                var _ = dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Normal, OnCollectionChanged);
            }
        }

        private void OnItemRemoved(TKey key)
        {
            if (dispatcher.HasThreadAccess)
            {
                MapChanged?.Invoke(this, new MapChangedEventArgs<TKey>(key, CollectionChange.ItemRemoved));
            }
            else
            {
                var _ = dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Normal, () => OnItemRemoved(key));
            }
        }

        private void OnItemReplaced(TKey key)
        {
            if (dispatcher.HasThreadAccess)
            {
                MapChanged?.Invoke(this, new MapChangedEventArgs<TKey>(key, CollectionChange.ItemChanged));
            }
            else
            {
                var _ = dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Normal, () => OnItemReplaced(key));
            }
        }
        
        private void OnItemInserted(TKey key)
        {
            if (dispatcher.HasThreadAccess)
            {
                MapChanged?.Invoke(this, new MapChangedEventArgs<TKey>(key, CollectionChange.ItemInserted));
            }
            else
            {
                var _ = dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Normal, () => OnItemInserted(key));
            }
        }
        private class MapChangedEventArgs<T> : IMapChangedEventArgs<T>
        {
            public MapChangedEventArgs(T key, CollectionChange change)
            {
                CollectionChange = change;
                Key = key;
            }
            public CollectionChange CollectionChange { get; }

            public T Key { get; }
        }
    }
}
