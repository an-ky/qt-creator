import qbs.base 1.0

import "../QtcPlugin.qbs" as QtcPlugin

QtcPlugin {
    name: "Bookmarks"

    Depends { name: "qt"; submodules: ['gui'] }
    Depends { name: "utils" }
    Depends { name: "extensionsystem" }
    Depends { name: "aggregation" }
    Depends { name: "Core" }
    Depends { name: "ProjectExplorer" }
    Depends { name: "TextEditor" }
    Depends { name: "find" }
    Depends { name: "Locator" }

    Depends { name: "cpp" }
    cpp.includePaths: [
        "..",
        "../../libs",
        buildDirectory
    ]

    files: [
        "bookmarksplugin.h",
        "bookmark.h",
        "bookmarkmanager.h",
        "bookmarks_global.h",
        "bookmarksplugin.cpp",
        "bookmark.cpp",
        "bookmarkmanager.cpp",
        "bookmarks.qrc",
    ]
}




