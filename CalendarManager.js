/**
 * This exposes the native CalendarManager module as a JS module.
 * It has a function 'addEvent' which takes the following parameters:
 *
 * 1. String name: A string with the name of the event
 * 2. Object details: the details of the event to be added in the
 * following format:
 *     {
 *       location: string
 *       startTime: Number - number of miliseconds since epoch
 *       endTime: Number - number of miliseconds since epoch
 *     }
 *
 */
import { NativeModules } from 'react-native';
export default NativeModules.CalendarManager;
