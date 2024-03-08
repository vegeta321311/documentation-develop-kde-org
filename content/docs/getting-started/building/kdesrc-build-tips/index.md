---
title: "Tips and tricks"
description: "TODO"
weight: 14
group: "kdesrc-build"
---

## Viewing colored build logs

Currently, the log file include escape symbols (that are used to color the text, or format it as bold for example). To be able to view it as expected, you can use Sublime with the [https://github.com/aziz/SublimeANSI ANSI color] plugin.

Alternatively, you can open logs with `cat` in Konsole when clicking. Because the file extension is ".log", it is not recognized as a text file, so the [option](https://discuss.kde.org/t/ctrl-click-on-a-py-file-listing-in-konsole-opens-kate-instead-of-default-editor/3406/4?u=ashark ) to change text editor command is not applied. Instead, open the **System Settings | File Associations**, search for "text/x-log" mime type. Press *Add* to add a new association and select Konsole. Now  edit the application's arguments with this text: `--hold -e /usr/bin/cat %U`.

Now when you will Ctrl + click on the text like `file:///home/username/kde6/src/log/2023-12-31-01/ark/build.log`, the new Konsole window will appear, with text formatted. As a bonus, you get a clickable lines that say in which line error occured.

Alternatively, you can create a wrapper script to strip out the ansi code characters.

```
cd ~/kde
./kdesrc-build $@
sed -i $'s/\033[][^A-Za-z]*[A-Za-z]//g' ~/kde/src/log/latest/"$1"/build.log
```

It will strip the log for the first module built with kdesrc-build.

## Prevent accidental src/ folder deletion

When you want to start the whole build from scratch, by deleting your `~/kde/build` and `~/kde/usr`, you may accidentally delete your `~/kde/src`. To protect yourself from that, you [can set the immutable flag to that directory](https://wiki.archlinux.org/title/File_permissions_and_attributes#File_attributes):

```
sudo chattr +i ~/kde/src
```

Now you have write permissions to the folder, but you cannot delete it.
