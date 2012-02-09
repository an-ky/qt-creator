import qbs.base 1.0

import "../QtcPlugin.qbs" as QtcPlugin

QtcPlugin {
    name: "Valgrind"

    Depends { name: "qt"; submodules: ['gui', 'network'] }
    Depends { name: "utils" }
    Depends { name: "extensionsystem" }
    Depends { name: "aggregation" }
    Depends { name: "Core" }
    Depends { name: "AnalyzerBase" }
    Depends { name: "ProjectExplorer" }
    Depends { name: "TextEditor" }
    Depends { name: "RemoteLinux" }
    Depends { name: "symbianutils"}
    Depends { name: "CPlusPlus"}

    Depends { name: "cpp" }
    cpp.includePaths: [
        ".",
        "valgrind",
        "..",
        "../../libs",
        buildDirectory
    ]

    files: [
        "callgrindcostdelegate.cpp",
        "callgrindcostdelegate.h",
        "callgrindcostview.cpp",
        "callgrindcostview.h",
        "callgrindengine.cpp",
        "callgrindengine.h",
        "callgrindhelper.cpp",
        "callgrindhelper.h",
        "callgrindnamedelegate.cpp",
        "callgrindnamedelegate.h",
        "callgrindtextmark.cpp",
        "callgrindtextmark.h",
        "callgrindtool.cpp",
        "callgrindtool.h",
        "callgrindvisualisation.cpp",
        "callgrindvisualisation.h",
        "memcheckengine.cpp",
        "memcheckengine.h",
        "memcheckerrorview.cpp",
        "memcheckerrorview.h",
        "memchecktool.cpp",
        "memchecktool.h",
        "suppressiondialog.cpp",
        "suppressiondialog.h",
        "valgrindconfigwidget.cpp",
        "valgrindconfigwidget.h",
        "valgrindconfigwidget.ui",
        "valgrindengine.cpp",
        "valgrindengine.h",
        "valgrindplugin.cpp",
        "valgrindplugin.h",
        "valgrindsettings.cpp",
        "valgrindsettings.h",
        "valgrindtool.cpp",
        "valgrindtool.h",
        "workarounds.cpp",
        "workarounds.h",
        "valgrindprocess.cpp",
        "valgrindprocess.h",
        "valgrindrunner.cpp",
        "valgrindrunner.h",
        "callgrind/callgrindabstractmodel.h",
        "callgrind/callgrindcallmodel.cpp",
        "callgrind/callgrindcallmodel.h",
        "callgrind/callgrindcontroller.cpp",
        "callgrind/callgrindcontroller.h",
        "callgrind/callgrindcostitem.cpp",
        "callgrind/callgrindcostitem.h",
        "callgrind/callgrindcycledetection.cpp",
        "callgrind/callgrindcycledetection.h",
        "callgrind/callgrinddatamodel.cpp",
        "callgrind/callgrinddatamodel.h",
        "callgrind/callgrindfunction.cpp",
        "callgrind/callgrindfunction.h",
        "callgrind/callgrindfunction_p.h",
        "callgrind/callgrindfunctioncall.cpp",
        "callgrind/callgrindfunctioncall.h",
        "callgrind/callgrindfunctioncycle.cpp",
        "callgrind/callgrindfunctioncycle.h",
        "callgrind/callgrindparsedata.cpp",
        "callgrind/callgrindparsedata.h",
        "callgrind/callgrindparser.cpp",
        "callgrind/callgrindparser.h",
        "callgrind/callgrindproxymodel.cpp",
        "callgrind/callgrindproxymodel.h",
        "callgrind/callgrindrunner.cpp",
        "callgrind/callgrindrunner.h",
        "callgrind/callgrindstackbrowser.cpp",
        "callgrind/callgrindstackbrowser.h",
        "memcheck/memcheckrunner.cpp",
        "memcheck/memcheckrunner.h",
        "xmlprotocol/announcethread.cpp",
        "xmlprotocol/announcethread.h",
        "xmlprotocol/error.cpp",
        "xmlprotocol/error.h",
        "xmlprotocol/errorlistmodel.cpp",
        "xmlprotocol/errorlistmodel.h",
        "xmlprotocol/frame.cpp",
        "xmlprotocol/frame.h",
        "xmlprotocol/modelhelpers.cpp",
        "xmlprotocol/modelhelpers.h",
        "xmlprotocol/parser.cpp",
        "xmlprotocol/parser.h",
        "xmlprotocol/stack.cpp",
        "xmlprotocol/stack.h",
        "xmlprotocol/stackmodel.cpp",
        "xmlprotocol/stackmodel.h",
        "xmlprotocol/status.cpp",
        "xmlprotocol/status.h",
        "xmlprotocol/suppression.cpp",
        "xmlprotocol/suppression.h",
        "xmlprotocol/threadedparser.cpp",
        "xmlprotocol/threadedparser.h"
    ]
}

