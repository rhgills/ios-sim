/* Author: Landon Fuller <landonf@plausiblelabs.com>
 * Copyright (c) 2008-2011 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * See the LICENSE file for the license on the source code in this file.
 */

#import <Foundation/Foundation.h>
#import <iPhoneSimulatorRemoteClient/iPhoneSimulatorRemoteClient.h>
#import "version.h"

@interface iPhoneSimulator : NSObject <DTiPhoneSimulatorSessionDelegate> {
@private
  DTiPhoneSimulatorSystemRoot *sdkRoot;
  NSFileHandle *stdoutFileHandle;
  NSFileHandle *stderrFileHandle;
  BOOL startOnly;
  BOOL activateOnStartup;
  BOOL exitOnStartup;
  BOOL shouldStartDebugger;
  BOOL useGDB;
  BOOL verbose;
  BOOL alreadyPrintedData;
  BOOL retinaDevice;
  BOOL tallDevice;
  
  char *currentArgument;
  int i;
  int argc;
  char **argv;
  
  NSTimeInterval timeout;
  NSString *family;
  NSString *uuid;
  NSString *stdoutPath;
  NSString *stderrPath;
  NSMutableDictionary *environment;
  
  BOOL stopParsing;
}

- (void)runWithArgc:(int)argc argv:(char **)argv;

- (void)createStdioFIFO:(NSFileHandle **)fileHandle ofType:(NSString *)type atPath:(NSString **)path;
- (void)removeStdioFIFO:(NSFileHandle *)fileHandle atPath:(NSString *)path;

@end
