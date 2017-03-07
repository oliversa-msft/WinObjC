//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <TestFramework.h>
#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"
#import <UIKit/UITextField.h>

// Re-use existing sample code for validation
#import "UIKitControls/UITextFieldWithControlsViewController.h"

class UITextFieldTests {
public:
    BEGIN_TEST_CLASS(UITextFieldTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UITextFieldTestsSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(UITextFieldTestsCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    TEST_METHOD(CreateXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            // TODO: Switch to UIKit.Xaml projections when they're available.
            Microsoft::WRL::ComPtr<IInspectable> xamlElement;
            XamlCreateTextBox(&xamlElement);
            ASSERT_TRUE(xamlElement);
        });
    }

    TEST_METHOD(GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIView* view = [[[UITextField alloc] init] autorelease];
            WXFrameworkElement* backingElement = [view xamlElement];
            ASSERT_TRUE(backingElement);

            // TODO: Fix up when UITextField moves fully to XAML
            ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
        });
    }

    TEST_METHOD(ShowUITextFieldViewController) {
        StrongId<UITextFieldWithControlsViewController> textFieldVC;
        textFieldVC.attach([[UITextFieldWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldVC, 3.0f);
    }
};