---
title: Tooltip
group: assistance
subgroup: help
---

Purpose
-------

A tooltip is a pop-up window that provides more information on an
element under the mouse cursor, such as toolbar controls without caption
or command buttons. Tooltips provide additional descriptive text
including formatting and icons. Tips eliminate the need to always have
descriptive text on the screen. Novice users will use hovering to show
tooltips to become familiar with the interface. This time-delay
mechanism makes tips very convenient, but it also reduces their
discoverability. When tips are used consistently they support user's
expectation and foster predictability.

Guidelines
----------

### Is this the right control?

-   Use tips to label unlabeled controls and to provide additional
    information.
-   Don't use tips for warnings.

### Behavior

-   Whenever appropriate, provide keyboard shortcuts and default values.
-   Tooltips for a disabled control should include information regarding
    the disabled state of the control. Include this information even if
    the control is enabled. For instance: 'Go to the next unread
    message' in the case of enabled controls and 'Go to the next
    unread message (No unread messages left)' when disabled.
-   Consider adding small informational buttons for touch screen use.
-   When necessary, there should be a way for users to find more help.
    Consider pointing users to additional help resources
    by making the tip expandable (e.g. by pressing Shift) or adding
    references or hyperlinks to manuals or wikis.
-   Users might invoke tips on hover by accident. Minimise the risk of
    tips covering space that the user is currently interested in by
    placing the popup out of the way, by keeping the text short or by
    reducing the total area that shows tips on hover.

### Appearance

-   Format and organize content in tooltips to make it easier to read
    and scan. The information should be:
    -   concise: large, unformatted blocks of text are difficult to read
        and overwhelming
    -   helpful: it should add information, not repeat information
    -   supplemental: important information should be communicated using
        self-explanatory control labels or in-place supplemental text
    -   static: tips should not change from one instance to the next
-   Don't use icons and formattings for tips of unlabeled controls.
-   Use tool-tips with icons and formatting
    -   if tips describe comprehensive functions,
    -   when content is lengthy and formatting improves readability
    -   for tips that are implemented primarily for joy of use.

Code
----

### Kirigami

- Kirigami: [ApplicationWindow](docs:kirigami2;ApplicationWindow)
- KXM: [Contextual Help Button](https://api.kde.org/frameworks/kdeclarative/html/classorg_1_1kde_1_1kcm_1_1ContextualHelpButton.html)
- QML: [MenuBar](https://doc.qt.io/qt-5/qml-qtquick-controls-menubar.html)

### Qt Widgets

- Qt: [QWidget::setToolTip()](https://doc.qt.io/qt-6/qwidget.html#toolTip-prop), [QAction::setToolTip()](https://doc.qt.io/qt-6/qaction.html#toolTip-prop), [QWidget::setWhatsThis()](https://doc.qt.io/qt-6/qwidget.html#whatsThis-prop), [QAction::setWhatsThis()](https://doc.qt.io/qt-6/qaction.html#whatsThis-prop)
- KDE Frameworks: When using [KToolTipHelper](https://api.kde.org/frameworks/kxmlgui/html/classKToolTipHelper.html) tooltips of actions will show their first keyboard shortcut by default and tooltips become expandable if there is whatsThis() available. For this to work, KToolTipHelper will need to be installed as an event filter on the [QApplication](https://doc.qt.io/qt-6/qapplication.html). This is the default for applications using [KMainWindow](https://api.kde.org/frameworks/kxmlgui/html/classKMainWindow.html).

### Plasma components

- [Plasma ToolTip](docs:plasma;ToolTip)
