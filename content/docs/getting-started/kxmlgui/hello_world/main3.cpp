#include <QApplication>
#include <KMessageBox>
#include <KAboutData>
#include <KLocalizedString>
#include <QCommandLineParser>

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("tutorial1");
    
    KAboutData aboutData(
        // The program name used internally. (componentName)
        QStringLiteral("tutorial1"),
        // A displayable program name string. (displayName)
        i18n("Tutorial 1"),
        // The program version string. (version)
        QStringLiteral("1.0"),
        // Short description of what the app does. (shortDescription)
        i18n("Displays a KMessageBox popup"),
        // The license this code is released under
        KAboutLicense::GPL,
        // Copyright Statement (copyrightStatement = QString())
        i18n("(c) 2021"),
        // Optional text shown in the About box.
        // Can contain any information desired. (otherText)
        i18n("Some text..."),
        // The program homepage string. (homePageAddress = QString())
        QStringLiteral("https://example.com/"),
        // The bug report email address
        // (bugsEmailAddress = QLatin1String("submit@bugs.kde.org")
        QStringLiteral("submit@bugs.kde.org"));

    aboutData.addAuthor(
        i18n("Name"),
        i18n("Author Role"),
        QStringLiteral("your@email.com"),
        QStringLiteral("https://your.website.com"),
        QStringLiteral("OCS Username"));

    KAboutData::setApplicationData(aboutData);

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);
    
    KGuiItem primaryAction(
        i18n("Hello"), QString(),
        i18n("This is a tooltip"),
        i18n("This is a WhatsThis help text."));

    return KMessageBox::questionTwoActions(
        nullptr,
        i18n("Hello World!\n"
             "This messagebox was made with KDE Frameworks."),
        i18n("Hello Title"), primaryAction, KStandardGuiItem::cancel())
        == KMessageBox::PrimaryAction ? EXIT_SUCCESS : EXIT_FAILURE;
}