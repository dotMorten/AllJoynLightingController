# AllJoyn Lighting Service Controller

A Windows Universal App implementation of the AllJoyn Lighting Service Framework Controller for running on Windows 10 Iot Core.

Supports:
 - Lamps
 - Lamp Groups
 - Presets
 - Scenes
 - MasterScenes

The controller discovers and controls any AllJoyn lamp on the local network.

For documentation on the Lighting Service Framework Controller, see the AllJoyn documentation here:
https://git.allseenalliance.org/cgit/interfaces.git/tree/interfaces/org.allseen.LSF.ControllerService?h=b1eb080e4ecaa218ea12b7f81ffa5150ca71d678


To add AllJoyn enabled bulbs to your network, you can use the following:
- Purchase LIFX bulbs which supports AllJoyn out of the box: www.lifx.com
- Use my Philips Hue DSB to expose Hue bulbs as AllJoyn: https://github.com/dotMorten/AllJoynPhilipsHueDSB
- Mock lights in an app using my AllJoyn Device Simulator for Bulb Mocking: https://github.com/dotMorten/AllJoynDeviceSimulator
- Run the Luminaire bulb simulator for Android: https://play.google.com/store/apps/details?id=com.qualcomm.luminaire
