//
// Created by jedikarix on 11.12.2019.
//

#ifndef PHUS_EDAMI_SEQUENCE_H
#define PHUS_EDAMI_SEQUENCE_H

#include <list>
#include <set>
#include <map>

typedef unsigned Item;

typedef std::map<Item, unsigned> Transaction;
typedef std::list<Transaction> Sequence;
typedef std::map<Item, unsigned> ProfitTable;
typedef std::list<Sequence> SDB;

inline bool has_item(const Item& item, const Transaction& transaction);
bool has_item(const Item& item, const Sequence& sequence);
inline unsigned item_count(const Item& item, const Transaction& transaction);
unsigned transaction_utility(const Transaction& transaction, const ProfitTable& profit_table);
unsigned utility_of_item(const Item& item, const Sequence& seq, const ProfitTable& profit_table);
unsigned utility_of_subsequence(const Sequence& subseq, const Sequence& seq, const ProfitTable& profit_table);
unsigned actual_sequence_utility(const Item& item, const SDB& sdb, const ProfitTable& profit_table);
unsigned actual_sequence_utility(const Sequence& seq, const SDB& sdb, const ProfitTable& profit_table);
unsigned sequence_utility(const Sequence& seq, const ProfitTable& profit_table);
unsigned sequence_utility_upper_bound(const Sequence& seq, const SDB& sdb, const ProfitTable& profit_table);
unsigned sequence_utility_upper_bound(const Item& item, const SDB& sdb, const ProfitTable& profit_table);

Transaction remove_items_from_transaction(const std::set<Item>& items, const Transaction& transaction);
Sequence remove_items_from_sequence(const std::set<Item>& items, const Sequence& sequence);
SDB remove_items_from_SDB(const std::set<Item>& items, const SDB& sdb);
#endif //PHUS_EDAMI_SEQUENCE_H
