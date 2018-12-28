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

#ifndef _WCDB_CORECONST_H
#define _WCDB_CORECONST_H

#define WCDB_BASIC_CONFIG_NAME "com.Tencent.WCDB.Config.Basic"
#define WCDB_BACKUP_CONFIG_NAME "com.Tencent.WCDB.Config.Backup"
#define WCDB_CHECKPOINT_CONFIG_NAME "com.Tencent.WCDB.Config.Checkpoint"
#define WCDB_TOKENIZE_CONFIG_NAME "com.Tencent.WCDB.Config.Tokenize"
#define WCDB_CIPHER_CONFIG_NAME "com.Tencent.WCDB.Config.Cipher"
#define WCDB_SQL_TRACE_CONFIG_NAME "com.Tencent.WCDB.Config.SQLTrace"
#define WCDB_PERFORMANCE_TRACE_CONFIG_NAME                                     \
    "com.Tencent.WCDB.Config.PerformanceTrace"
#define WCDB_GLOBAL_SQL_TRACE_CONFIG_NAME                                      \
    "com.Tencent.WCDB.Config.GlobalSQLTrace"
#define WCDB_GLOBAL_PERFORMANCE_TRACE_CONFIG_NAME                              \
    "com.Tencent.WCDB.Config.GlobalPerformanceTrace"

namespace WCDB {

// Migration Queue
static constexpr const char* MigrationQueueName = "com.Tencent.WCDB.Queue.Migration";
static constexpr const double MigrationQueueTimeIntervalForMigrating = 1.0f;
static constexpr const int MigrationQueueTolerableFailures = 3;

// Corrupt Queue
static constexpr const char* CorruptionQueueName = "com.Tencent.WCDB.Queue.Corruption";
static constexpr const double CorruptionQueueTimeIntervalForInvokingEvent = 5.0f;

// Checkpoint Queue
static constexpr const char* CheckpointQueueName = "com.Tencent.WCDB.Queue.Checkpoint";
static constexpr const int CheckpointQueueFramesThresholdForTruncating = 10 * 1024;
static constexpr const double CheckpointQueueDelayForRetryingAfterFailure = 10.0;

// Backup Queue
static constexpr const char* BackupQueueName = "com.Tencent.WCDB.Queue.Backup";
static constexpr double BackupQueueDelayForRetryingAfterFailure = 15.0;

// Checkpoint Config
static constexpr const char* CheckpointConfigName = WCDB_CHECKPOINT_CONFIG_NAME;
static constexpr const int CheckpointConfigFramesThresholdForCritical = 100;
static constexpr const double CheckpointConfigDelayForCritical = 1.0;
static constexpr const double CheckpointConfigDelayForNonCritical = 10.0;

// Backup Config
static constexpr const char* BackupConfigName = WCDB_BACKUP_CONFIG_NAME;
static constexpr const int BackupConfigFramesIntervalForNonCritical = 100;
static constexpr const int BackupConfigFramesIntervalForCritical = 300;
static constexpr const double BackupConfigDelayForCritical = 0;
static constexpr const double BackupConfigDelayForNonCritical = 1.0;

// Basic Config
static constexpr const char* BasicConfigName = WCDB_BASIC_CONFIG_NAME;

// Tokenize Config
static constexpr const char* TokenizeConfigName = WCDB_TOKENIZE_CONFIG_NAME;

// Cipher Config
static constexpr const char* CipherConfigName = WCDB_CIPHER_CONFIG_NAME;

// SQL Trace Config
static constexpr const char* SQLTraceConfigName = WCDB_SQL_TRACE_CONFIG_NAME;

// Performance Trace Config
static constexpr const char* PerformanceTraceConfigName = WCDB_PERFORMANCE_TRACE_CONFIG_NAME;

// Global SQL Trace Config
static constexpr const char* GlobalSQLTraceConfigName = WCDB_GLOBAL_SQL_TRACE_CONFIG_NAME;

// Global Performance Trace Config
static constexpr const char* GlobalPerformanceTraceConfigName
= WCDB_GLOBAL_PERFORMANCE_TRACE_CONFIG_NAME;

// Notifier
static constexpr const char* NotifierTagPreprocessorName
= "com.Tencent.WCDB.Notifier.PreprocessTag";
static constexpr const char* NotifierPathPreprocessorName
= "com.Tencent.WCDB.Notifier.PreprocessPath";
constexpr const char* NotifierLoggerName = "com.Tencent.WCDB.Notifier.Log";

// Handle Pool
static constexpr const int HandlePoolHandleCountThreshold = 16;

} // namespace WCDB

#endif /* _WCDB_CORECONST_H */