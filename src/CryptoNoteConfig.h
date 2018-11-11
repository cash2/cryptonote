// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2018 The Cash2 developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 9; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = ((uint64_t)(-1)); // 18,446,744,073,709,551,616 blocks
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x6; // all Cash2 addresses start with a '2' 
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 3 * DIFFICULTY_TARGET;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 11;
const uint64_t MONEY_SUPPLY                                  = UINT64_C(15000000000000000); // 15,000,000.000000000 total coins
const unsigned EMISSION_SPEED_FACTOR                         = 24;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 60 * 24 * 60 * 60 / DIFFICULTY_TARGET; // number of blocks produced in 60 days
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1024 * 1024; //size of block (bytes) after which reward for block calculated using block size, 1 mb
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 9; // number of digits after decimal poin
const uint64_t MINIMUM_FEE                                   = 0; // free transactions
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;
const uint64_t MAX_MIXIN                                     = 3;
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 158; // blocks, N = int(45 * (600 / T) ^ 0.3)), N is the difficulty window, T is the target time
const size_t   DIFFICULTY_CUT                                = 40;  // timestamps to cut after sorting (originally 60)
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");
const size_t   MAX_BLOCK_SIZE_INITIAL                        = 2 * 1024 * 1024; // 2 mb
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;
const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 5; //seconds, 5 minutes
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 5; //seconds, 5 minutes
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 1;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx
const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;
const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDEXES_FILENAME[]      = "blockchainindexes.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";

} // end namespace parameters

const char     CRYPTONOTE_NAME[]                             = "cash2";
const char     GENESIS_COINBASE_TX_HEX[]                     = "";
const uint8_t  CURRENT_TRANSACTION_VERSION                   = 1;
const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        = 10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            = 200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         = 1000;
const int      P2P_DEFAULT_PORT                              = 12275;
const int      RPC_DEFAULT_PORT                              = 12276;
const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                = 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 = 5000;
const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

//seed nodes
const std::initializer_list<const char*> SEED_NODES = {};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

const std::initializer_list<CheckpointData> CHECKPOINTS = {};

} // end namespace CryptoNote

#define ALLOW_DEBUG_COMMANDS
