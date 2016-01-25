//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#import <CoreMotion/CoreMotionExport.h>
#import <Foundation/NSObject.h>
#import <objc/runtime.h>

@class CMSensorDataList;

COREMOTION_EXPORT_CLASS
@interface CMSensorRecorder : NSObject <NSObject>
+ (BOOL)isAccelerometerRecordingAvailable STUB_METHOD;
+ (BOOL)isAuthorizedForRecording STUB_METHOD;
- (CMSensorDataList*)accelerometerDataSince:(uint64_t)identifier STUB_METHOD;
@end