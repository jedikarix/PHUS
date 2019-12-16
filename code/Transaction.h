//
// Created by jedikarix on 13.12.2019.
//

#ifndef PHUS_EDAMI_TRANSACTION_H
#define PHUS_EDAMI_TRANSACTION_H

#include <map>
#include <set>

typedef unsigned Item;
typedef std::map<Item, unsigned> ProfitTable;
typedef std::map<Item, unsigned> Transaction;

/**
 * Determines if transaction contains given item.
 * @param item
 * @param transaction
 * @return
 */
inline bool has_item(const Item& item, const Transaction& transaction);

/**
 * Counts items in transaction.
 * @param item
 * @param transaction
 * @return
 */
inline unsigned item_count(const Item& item, const Transaction& transaction);

/**
 * Computes utility of transaction. Sums items quantities multiplied by their utility in profit_table.
 * @param transaction
 * @param profit_table
 * @return
 */
unsigned transaction_utility(const Transaction& transaction, const ProfitTable& profit_table);

/**
 * Generates transaction based on given transaction. Keeps items from given set only.
 * @param items
 * @param transaction
 * @return new filtered transaction
 */
Transaction filter_transaction(const std::set<Item>& items, const Transaction& transaction);

#endif //PHUS_EDAMI_TRANSACTION_H
