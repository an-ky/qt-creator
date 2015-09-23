/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd
** All rights reserved.
** For any questions to The Qt Company, please use contact form at
** http://www.qt.io/contact-us
**
** This file is part of the Qt Creator Enterprise Auto Test Add-on.
**
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.
**
** If you have questions regarding the use of this file, please use
** contact form at http://www.qt.io/contact-us
**
****************************************************************************/

#include "testresult.h"

namespace Autotest {
namespace Internal {

FaultyTestResult::FaultyTestResult(Result::Type result, const QString &description)
{
    setResult(result);
    setDescription(description);
}

TestResult::TestResult()
    : TestResult(QString())
{
}

TestResult::TestResult(const QString &className)
    : m_class(className)
    , m_result(Result::INVALID)
    , m_line(0)
{
}

Result::Type TestResult::resultFromString(const QString &resultString)
{
    if (resultString == QLatin1String("pass"))
        return Result::PASS;
    if (resultString == QLatin1String("fail"))
        return Result::FAIL;
    if (resultString == QLatin1String("xfail"))
        return Result::EXPECTED_FAIL;
    if (resultString == QLatin1String("xpass"))
        return Result::UNEXPECTED_PASS;
    if (resultString == QLatin1String("skip"))
        return Result::SKIP;
    if (resultString == QLatin1String("qdebug"))
        return Result::MESSAGE_DEBUG;
    if (resultString == QLatin1String("warn") || resultString == QLatin1String("qwarn"))
        return Result::MESSAGE_WARN;
    if (resultString == QLatin1String("qfatal"))
        return Result::MESSAGE_FATAL;
    if (resultString == QLatin1String("bpass"))
        return Result::BLACKLISTED_PASS;
    if (resultString == QLatin1String("bfail"))
        return Result::BLACKLISTED_FAIL;
    qDebug("Unexpected test result: %s", qPrintable(resultString));
    return Result::INVALID;
}

Result::Type TestResult::toResultType(int rt)
{
    if (rt < Result::FIRST_TYPE || rt > Result::LAST_TYPE)
        return Result::INVALID;

    return (Result::Type)rt;
}

QString TestResult::resultToString(const Result::Type type)
{
    if (type >= Result::INTERNAL_MESSAGES_BEGIN && type <= Result::INTERNAL_MESSAGES_END)
        return QString();

    switch (type) {
    case Result::PASS:
        return QLatin1String("PASS");
    case Result::FAIL:
        return QLatin1String("FAIL");
    case Result::EXPECTED_FAIL:
        return QLatin1String("XFAIL");
    case Result::UNEXPECTED_PASS:
        return QLatin1String("XPASS");
    case Result::SKIP:
        return QLatin1String("SKIP");
    case Result::BENCHMARK:
        return QLatin1String("BENCH");
    case Result::MESSAGE_DEBUG:
        return QLatin1String("DEBUG");
    case Result::MESSAGE_WARN:
        return QLatin1String("WARN");
    case Result::MESSAGE_FATAL:
        return QLatin1String("FATAL");
    case Result::BLACKLISTED_PASS:
        return QLatin1String("BPASS");
    case Result::BLACKLISTED_FAIL:
        return QLatin1String("BFAIL");
    default:
        return QLatin1String("UNKNOWN");
    }
}

QColor TestResult::colorForType(const Result::Type type)
{
    if (type >= Result::INTERNAL_MESSAGES_BEGIN && type <= Result::INTERNAL_MESSAGES_END)
        return QColor("transparent");

    switch (type) {
    case Result::PASS:
        return QColor("#009900");
    case Result::FAIL:
        return QColor("#a00000");
    case Result::EXPECTED_FAIL:
        return QColor("#00ff00");
    case Result::UNEXPECTED_PASS:
        return QColor("#ff0000");
    case Result::SKIP:
        return QColor("#787878");
    case Result::BLACKLISTED_PASS:
        return QColor(0, 0, 0);
    case Result::BLACKLISTED_FAIL:
        return QColor(0, 0, 0);
    case Result::MESSAGE_DEBUG:
        return QColor("#329696");
    case Result::MESSAGE_WARN:
        return QColor("#d0bb00");
    case Result::MESSAGE_FATAL:
        return QColor("#640000");
    default:
        return QColor("#000000");
    }
}

bool operator==(const TestResult &t1, const TestResult &t2)
{
    return t1.className() == t2.className()
            && t1.testCase() == t2.testCase()
            && t1.dataTag() == t2.dataTag()
            && t1.result() == t2.result();
}

} // namespace Internal
} // namespace Autotest
