// Copyright (c) 2012-2018 The Peercoin developers
// Copyright (c) 2018- The Vaultress developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef VAULTRESS_KERNEL_H
#define VAULTRESS_KERNEL_H

#include "main.h"

// MODIFIER_INTERVAL: time to elapse before new modifier is computed
static const unsigned int MODIFIER_INTERVAL = 2 * 60 * 60;	// equates to GetStakeModifierSelectionInterval = 2.93 days
extern unsigned int nModifierInterval;

// MODIFIER_INTERVAL_RATIO:
// ratio of group interval length between the last group and the first group
static const int MODIFIER_INTERVAL_RATIO = 3;

// Whether a given coinstake is subject to new v0.3 protocol
bool IsProtocolV03(unsigned int nTimeCoinStake);
// Whether a given block is subject to new v0.4 protocol
bool IsProtocolV04(unsigned int nTimeBlock);
// Whether the given transaction is subject to new v0.5 protocol of allowing 0 as tx out
bool IsProtocolV05A(unsigned int nTimeTx);
// Whether the given transaction is subject to new v0.5 protocol of updated StakeKernelHash
bool IsProtocolV05B(unsigned int nTimeTx);

// Whether a given block is subject to new v0.6 protocol
// Test against previous block index! (always available)
bool IsProtocolV06(const CBlockIndex *pindexPrev);

// Compute the hash modifier for proof-of-stake
bool ComputeNextStakeModifier(const CBlockIndex* pindexCurrent, uint64& nStakeModifier, bool& fGeneratedStakeModifier);

// Check whether stake kernel meets hash target
// Sets hashProofOfStake on success return
bool CheckStakeKernelHash(unsigned int nBits, const CBlockHeader& blockFrom, unsigned int nTxPrevOffset, const CTransaction& txPrev, const COutPoint& prevout, unsigned int nTimeTx, uint256& hashProofOfStake, bool fPrintProofOfStake=false);

// Check kernel hash target and coinstake signature
// Sets hashProofOfStake on success return
bool CheckProofOfStake(CValidationState &state, const CTransaction& tx, unsigned int nBits, uint256& hashProofOfStake);

// Check whether the coinstake timestamp meets protocol
bool CheckCoinStakeTimestamp(int64 nTimeBlock, int64 nTimeTx);

// Get stake modifier checksum
unsigned int GetStakeModifierChecksum(const CBlockIndex* pindex);

// Check stake modifier hard checkpoints
bool CheckStakeModifierCheckpoints(int nHeight, unsigned int nStakeModifierChecksum);

#endif // VAULTRESS_KERNEL_H
