//
// Created by 陈秋文 on 2022/6/11.
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

#include "JoinBridge.h"
#include "Column.hpp"
#include "Expression.hpp"
#include "Join.hpp"
#include "ObjectBridge.hpp"
#include "WinqBridge.hpp"

CPPJoin WCDBJoinCreateWithTableOrSubquery(CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturnValue(query, WCDB::TableOrSubquery, cppQuery, CPPJoin());
    WCDB::Join* join = new WCDB::Join();
    join->table(*cppQuery);
    return WCDBCreateCPPBridgedObject(CPPJoin, join);
}

void WCDBJoinWith(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->with(*cppQuery);
}

void WCDBJoinWithJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->join(*cppQuery);
}

void WCDBJoinWithLeftOuterJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->leftOuterJoin(*cppQuery);
}

void WCDBJoinWithLeftJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->leftJoin(*cppQuery);
}

void WCDBJoinWithInnerJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->innerJoin(*cppQuery);
}

void WCDBJoinWithCrossJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->crossJoin(*cppQuery);
}

void WCDBJoinWithNaturalJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->naturalJoin(*cppQuery);
}

void WCDBJoinWithNaturalLeftOuterJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->naturalLeftOuterJoin(*cppQuery);
}

void WCDBJoinWithNaturalLeftJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->naturalLeftJoin(*cppQuery);
}

void WCDBJoinWithNaturalInnerJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->naturalInnerJoin(*cppQuery);
}

void WCDBJoinWithNaturalCrossJoin(CPPJoin join, CPPTableOrSubquery query)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(query, WCDB::TableOrSubquery, cppQuery);
    cppJoin->naturalCrossJoin(*cppQuery);
}

void WCDBJoinConfigOn(CPPJoin join, CPPExpression expression)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetObjectOrReturn(expression, WCDB::Expression, cppExpression);
    cppJoin->on(*cppExpression);
}

void WCDBJoinConfigUsingColumn(CPPJoin join, const CPPColumn* columns, int columnNum)
{
    WCDBGetObjectOrReturn(join, WCDB::Join, cppJoin);
    WCDBGetCPPSyntaxListOrReturn(WCDB::Column, cppColumns, columns, columnNum);
    cppJoin->usingColumns(cppColumns);
}
