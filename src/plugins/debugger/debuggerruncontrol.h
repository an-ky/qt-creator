/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "debugger_global.h"
#include "debuggerconstants.h"

#include <projectexplorer/runconfiguration.h>

namespace Debugger {

class RemoteSetupResult;
class DebuggerStartParameters;
class DebuggerRunControl;

DEBUGGER_EXPORT DebuggerRunControl *createDebuggerRunControl(const DebuggerStartParameters &sp,
                                                             ProjectExplorer::RunConfiguration *runConfig,
                                                             QString *errorMessage,
                                                             Core::Id runMode = ProjectExplorer::Constants::DEBUG_RUN_MODE);

class DEBUGGER_EXPORT DebuggerRunControl : public ProjectExplorer::RunControl
{
    Q_OBJECT

public:
    DebuggerRunControl(ProjectExplorer::RunConfiguration *runConfig, Core::Id runMode);
    ~DebuggerRunControl() override;

    // ProjectExplorer::RunControl
    void start() override;
    bool promptToStop(bool *prompt = 0) const override;
    void stop() override; // Called from SnapshotWindow.

    void startFailed();
    void notifyEngineRemoteServerRunning(const QByteArray &msg, int pid);
    void notifyEngineRemoteSetupFinished(const RemoteSetupResult &result);
    void notifyInferiorIll();
    Q_SLOT void notifyInferiorExited();
    void quitDebugger();
    void abortDebugger();
    void debuggingFinished();

    void showMessage(const QString &msg, int channel = LogDebug);

    DebuggerStartParameters &startParameters(); // Used in Boot2Qt.

signals:
    void requestRemoteSetup();
    void aboutToNotifyInferiorSetupOk();
    void stateChanged(Debugger::DebuggerState state);
};

} // namespace Debugger
