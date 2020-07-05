/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include "TableBase.h"
#include <unordered_set>
#include <list>

namespace GCL {
namespace Serialization {

class TableContainer {
public:
	void Load();
	void Reload();
	void Clear();

	template <typename TTable>
	void EmplaceBack() {
		_EmplaceBack(TTable::GetInstance());
	}
	template <typename TTable>
	void Remove() {
		_Remove(TTable::GetInstance());
	}
	void RemoveAll();

private:
	void _EmplaceBack(ITable* table);
	void _Remove(ITable* table);

private:
	std::unordered_set<ITable*> _checkSets;
	// keep order
	std::list<ITable*> _tables;
};

} // namespace Serialization
} // namespace GCL