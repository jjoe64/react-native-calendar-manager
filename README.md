# react-native-calendar-manager

A calendar manager for React Native.
Exposes `addEvent` method which can save an event to an Android or iOS device's native calendar app.

It works with ReactNative v0.40.0

Hint: This is a fork of the project of fiveminutes hosted on BitBucket: `https://bitbucket.org/fiveminutes/react-native-calendar-manager`. I needed to change something and it's much better on Github so I decided to fork it and publish here. If the authors contact me, I will grant full permission.

## Supported React Native platforms

- Android
- iOS

## Plugin installation

Run `npm install --save https://github.com/jjoe64/react-native-calendar-manager.git`

### Automatic plugin linking using rnpm

You can use [`rnpm`](https://github.com/rnpm/rnpm) to add native dependencies automatically.
Just run:

`$ react-native link react-native-calendar-manager`

Which will link all native dependencies from the plugin.

It will also add a directory containing your app's AppDelegate to CalendarManager projects build path which is necessary for building the iOS dependencies.

### Manual plugin linking

#### iOS

1. Open your project in XCode, right click on `Libraries` and click `Add
   Files to "Your Project Name"` Look under `node_modules/react-native-calendar-manager` and add `CalendarManager.xcodeproj`.  
2. Add `libCalendarManager.a` to `Build Phases -> Link Binary With Libraries`
3. Click on `CalendarManager.xcodeproj` in `Libraries` and go the `Build
   Settings` tab. Double click the text to the right of `Header Search
   Paths` and verify that it has the lines `$(SRCROOT)/../../node_modules/react-native/React/**` and `$(SRCROOT)/node_modules/react-native/React/**` - if it
   doesn't, then add them. This is so XCode is able to find the headers that
   the `CalendarManager` source files are referring to by pointing to the
   header files installed within the `react-native` `node_modules`
   directory.
4. Add the line `$(SRCROOT)/../../ios/<YOUR PROJECT'S NAME>` as well, so that CalendarManager can find yor AppDelegate header file.
   
#### Android

1. in `android/settings.gradle`   
```
#!groovy
   ...
   include ':react-native-calendar-manager'
   project(':react-native-calendar-manager').projectDir = new File(rootProject.projectDir, '../node_modules/react-native-calendar-manager/android')

```

2. in `android/app/build.gradle` add:
```
#!groovy
   dependencies {
       ...
       compile project(':react-native-calendar-manager')
   }
```

3. and finally, in `android/src/main/java/com/{YOUR_APP_NAME}/MainActivity.java` add:
   
```
#!java
   //... MainActivity.java
   import com.shoutem.calendar.CalendarManagerPackage; // <--- This!
   //...

   @Override
   protected List<ReactPackage> getPackages() {
     return Arrays.<ReactPackage>asList(
       new MainReactPackage(),
       new CalendarManagerPackage() // <---- and This!
     );
   }

```


## Example
```javascript
import CalendarManager from 'react-native-calendar-manager';

const inTenMinutes = Date.now() + 1000 * 60 * 10;
const inTwentyMinutes = Date.now() + 1000 * 60 * 10 * 2;
CalendarManager.addEvent({
  name: 'Coffee',
  location: 'Heinzelova 33',
  startTime: inTenMinutes,
  endTime: inTwentyMinutes,
})


```
