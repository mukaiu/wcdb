//
// Created by 陈秋文 on 2022/6/9.
//

/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "FrameSpecBridge.h"
#include "Expression.hpp"
#include "FrameSpec.hpp"
#include "ObjectBridge.hpp"

CPPFrameSpec WCDBFrameSpecCreate()
{
    return WCDBCreateCPPBridgedObject(CPPFrameSpec, new WCDB::FrameSpec());
}
void WCDBFrameSpecConfigRange(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->range();
}

void WCDBFrameSpecConfigRows(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->rows();
}

void WCDBFrameSpecConfigUnboundedPreceding(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->unboundedPreceding();
}

void WCDBFrameSpecConfigPreceding(CPPFrameSpec frameSpec, CPPExpression expression)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    WCDBGetObjectOrReturn(expression, WCDB::Expression, cppExpression);
    cppFrameSpec->preceding(*cppExpression);
}

void WCDBFrameSpecConfigCurrentRow(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->currentRow();
}

void WCDBFrameSpecConfigBetweenUnboundedPreceding(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->betweenUnboundedPreceding();
}

void WCDBFrameSpecConfigBetweenPreceding(CPPFrameSpec frameSpec, CPPExpression expression)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    WCDBGetObjectOrReturn(expression, WCDB::Expression, cppExpression);
    cppFrameSpec->betweenPreceding(*cppExpression);
}

void WCDBFrameSpecConfigBetweenCurrentRow(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->betweenCurrentRow();
}

void WCDBFrameSpecConfigBetweenFollowing(CPPFrameSpec frameSpec, CPPExpression expression)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    WCDBGetObjectOrReturn(expression, WCDB::Expression, cppExpression);
    cppFrameSpec->betweenFollowing(*cppExpression);
}

void WCDBFrameSpecConfigAndPreceding(CPPFrameSpec frameSpec, CPPExpression expression)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    WCDBGetObjectOrReturn(expression, WCDB::Expression, cppExpression);
    cppFrameSpec->andPreceding(*cppExpression);
}

void WCDBFrameSpecConfigAndCurrentRow(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->andCurrentRow();
}

void WCDBFrameSpecConfigAndFollowing(CPPFrameSpec frameSpec, CPPExpression expression)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    WCDBGetObjectOrReturn(expression, WCDB::Expression, cppExpression);
    cppFrameSpec->andFollowing(*cppExpression);
}

void WCDBFrameSpecConfigAndUnboundedFollowing(CPPFrameSpec frameSpec)
{
    WCDBGetObjectOrReturn(frameSpec, WCDB::FrameSpec, cppFrameSpec);
    cppFrameSpec->andUnboundedFollowing();
}
