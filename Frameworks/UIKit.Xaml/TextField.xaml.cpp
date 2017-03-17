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
// clang-format does not like C++/CX
// clang-format off
#include "pch.h"
#include "TextField.xaml.h"

#include "ObjCXamlControls.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {
namespace Xaml {

TextField::TextField() {
    InitializeComponent();

    SetValue(UIKit::Xaml::Private::CoreAnimation::Layer::LayerContentProperty, LayerContentImage);
    SetValue(UIKit::Xaml::Private::CoreAnimation::Layer::SublayerCanvasProperty, this);

    Name = L"TextField";
}

// Accessor for our Layer content
Image^ TextField::LayerContent::get() {
    return LayerContentImage;
}

// Accessor for our Layer content
bool TextField::HasLayerContent::get() {
    return true;
}

// Accessor for our SublayerCanvas
Canvas^ TextField::SublayerCanvas::get() {
    // We *are* the sublayer canvas
    return this;
}

// Accessor for the LayerProperty that manages the BorderBrush of this TextField
Private::CoreAnimation::LayerProperty^ TextField::GetBorderBrushProperty() {
    return nullptr;
}

// Accessor for the LayerProperty that manages the BorderThickness of this TextField
Private::CoreAnimation::LayerProperty^ TextField::GetBorderThicknessProperty() {
    return nullptr;
}

TextBox^ TextField::TextBox::get() {
    return textFieldTB;
}

PasswordBox^ TextField::PasswordBox::get() {
    return textFieldPB;
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::TextField as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateTextField(IInspectable** created) {
    ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::TextField());
    *created = inspectable.Detach();
}

// Retrieves the UIKit::Xaml::TextField's backing TextBox as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldTextBox(const Microsoft::WRL::ComPtr<IInspectable>& TextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(TextField.Get()));
    return InspectableFromObject(textField->TextBox).Detach();
}

// Retrieves the UIKit::Xaml::TextField's backing PasswordBox as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldPasswordBox(const Microsoft::WRL::ComPtr<IInspectable>& TextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(TextField.Get()));
    return InspectableFromObject(textField->PasswordBox).Detach();
}
