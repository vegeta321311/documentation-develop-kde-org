---
title: Your first Flatpak
description: Learn how to create Flatpaks in three simple steps.
weight: 1
aliases:
  - /docs/flatpak/packaging/
---

Flatpak is a new package format in the Linux world that works on many Linux
distributions and gives back control to the application developers. Many Flatpak
applications are distributed via [Flathub](https://flathub.org), but Flatpak is
decentralized by nature and applications can be provided using alternatives sources, such as the [kdeapps](https://community.kde.org/Guidelines_and_HOWTOs/Flatpak#Applications) repository for nightly builds.

Flatpak applications can be downloaded using Discover (KDE Software Center), GNOME
Software and other software centers compatible with Flatpak.

One of its key differences to traditional packages is dependency management.
Instead of depending on many other packages and unpacking all of them into one system directory, flatpak uses runtimes.
Runtimes are collections of common frameworks and libraries used for specific types of applications. In our case, that's the [KDE Flatpak Runtime](https://invent.kde.org/packaging/flatpak-kde-runtime), which includes KDE Frameworks and Qt libraries.
Once users install the common KDE runtime, applications make use of its libraries, and can be distributed together with their more special library requirements (like a protocol implementation for an instant messenger) in one flatpak package.

Building flatpaks consists mostly of three steps:
* Finding and installing the necessary Flatpak SDK and Runtime for your application. Most can be found in the common flatpak repository, Flathub.

To install it, run:

`sudo flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo`

  The KDE Flatpak Runtime is called `org.kde.Sdk`. It can be used for KDE software and other applications making use of Qt.
  As runtimes are versioned, to make sure not to break other applications with sudden updates, you'll have to pick the latest available one.
  Flatpak will ask you to choose a version when running the install command `flatpak install org.kde.Sdk`.
  
* Writing a Flatpak manifest. Flatpak manifests can be written in JSON or YAML, depending on what you like better. The KDE Team on Flathub currently uses JSON.
  A list of all possible keys for a flatpak manifest can be found in the official [flatpak documentation](https://docs.flatpak.org/en/latest/flatpak-builder-command-reference.html#flatpak-manifest), but in many cases a minimal recipe is enough.
  
  This is a minimal manifest for Kate:

{{< code-toggle prefix="kate" >}}id: org.kde.kate
runtime: org.kde.Platform
runtime-version: "5.15"
sdk: org.kde.Sdk
command: kate
desktop-file-name-suffix: " (Nightly)"
finish-args:
  - "--share=ipc"
  - "--socket=x11"
  - "--socket=wayland"
modules:
  - name: kate
    buildsystem: cmake-ninja
    sources:
      - type: git
        url: https://invent.kde.org/utilities/kate.git
{{< /code-toggle >}}

  Dependencies can be added as modules just like the "kate" module that contains the application, but they must come first. Kate has an optional integration with Konsole, so to get it working, we need to include konsole before the kate module.
  
{{< code-toggle prefix="konsole" >}}name: konsole
buildsystem: cmake-ninja
sources:
  - type: git
    url: https://invent.kde.org/utilities/konsole.git
{{< /code-toggle >}}

* The third step is building the binary. Although the final binary will be built on a CI system, you'll need to test your manifest locally.
  A oneliner command for that is `sudo flatpak-builder build --install-deps-from=flathub --force-clean --ccache --install org.kde.kate.json`. It will pull all required dependencies from flathub if they exist, build the application in a directory called "build", clean the directory if needed, cache the build files so later builds will be faster, and automatically install it for you. If the flatpak you made provides a .desktop file, you'll find a new entry on your menu; otherwise you can test/execute it with `flatpak run org.kde.kate`.
  
{{< alert title="Tip!" color="success" >}}
If you install Flathub as `--user`, you won't need sudo to run any flatpak command, which allows you to build and install the app for your user only. The command then becomes `flatpak-builder build --user --install-deps-from=flathub --force-clean --ccache --install org.kde.kate.json`.
{{< /alert >}}

  
You can now submit your new manifest to [flatpak-kde-applications](https://invent.kde.org/packaging/flatpak-kde-applications)! It works as a testing grounds of sorts for nightlies (built every day) to ensure that your package runs well.
After testing it there for some time, you may submit a stable release to flathub.