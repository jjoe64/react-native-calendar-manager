//
//  CalendarManager.h
//  CalendarManager
//
//  Created by Vladimir Adamic on 12/05/16.
//  Copyright © 2016 ShoutEm. All rights reserved.
//

#ifndef CalendarManager_h
#define CalendarManager_h


#endif /* CalendarManager_h */
#import "RCTBridgeModule.h"
#import <EventKit/EventKit.h>
#import <EventKitUI/EventKitUI.h>

@interface CalendarManager : NSObject <RCTBridgeModule, EKEventEditViewDelegate>
@property (atomic, retain) EKEventStore *eventStore;
@end
