---
title: "Basic troubleshooting"
description: "What to do in case of build issues"
weight: 13
group: "kdesrc-build"
url: docs/getting-started/kdesrc-build-failure
---

Did one or more modules fail to build (displayed in red font) using `kdesrc-build`? Then here's what to do:

* Try building the failing module again from scratch using `kdesrc-build [failing module] --refresh-build`

* Make sure that you have all the dependencies for the failing module. Open the log file for the failing module which `kdesrc-build` will print the path at the end of its output. Scroll to the bottom of the log file and read the output to see what missing dependency it is complaining about. Then find and install the corresponding package using the package manager of your distribution. If several look relevant, install them all just to be safe. When you have the necessary dependencies, you can save time and resume from the failing module by adding `--resume-from [the name of the module that failed]` to your `kdesrc-build` command.

* Look at the KDE project's https://invent.kde.org GitLab project. If the project has a GitLab build pipeline and if the pipeline is broken, then it's not your fault.

* Ask for help in the the [#kde-devel](https://webchat.kde.org/#/room/#kde-devel:kde.org) channel on [Matrix](https://community.kde.org/Matrix) or [Libera Chat IRC](https://community.kde.org/Internet_Relay_Chat). See [Where to find the development team]({{< ref "developers" >}}).

* Looking into the error log is also helpful. For example, the build stopped at KWallet. You will need to go into `~/kde/src/log/latest/kwallet/error.log` and find what packages are missing.

* If you know what files are missing, but you don't know what packages provide them, you can ask your package manager. See https://wiki.archlinux.org/index.php/Pacman/Rosetta (see "Query the package which provides FILE").

* The problem might be in `~/kde/usr`. For example, a file in `~/kde/usr/include` was renamed or moved. You can help yourself by seeing if you can reproduce this issue in a clean new Virtual Machine (VM). If you cannot reproduce the issue in your VM, then a possible solution is to start with a new and clean kdesrc-build installation. This can be done by running something like `mv ~/.config/kdesrc-buildrc ~/.config/kdesrc-buildrc~bak ; mv ~/kde ~/kde~bak` and then installing kdesrc-build from scratch.

* More ideas about how to fix kdesrc-build issues are available here: [Get_Involved/development/Install_the_dependencies] and [Get_Involved/development/More].
