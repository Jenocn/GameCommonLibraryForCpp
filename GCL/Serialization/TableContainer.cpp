#include "TableContainer.h"

using namespace GCL::Serialization;

void TableContainer::Load() {
	for (auto table : _tables) {
		table->Load();
	}
}
void TableContainer::Reload() {
	for (auto table : _tables) {
		table->Reload();
	}
}

void TableContainer::Clear() {
	for (auto table : _tables) {
		table->Clear();
	}
}

void TableContainer::_EmplaceBack(ITable* table) {
	if (_checkSets.find(table) == _checkSets.end()) {
		_checkSets.emplace(table);
		_tables.emplace_back(table);
	}
}
void TableContainer::_Remove(ITable* table) {
	auto ite = _checkSets.find(table);
	if (ite != _checkSets.end()) {
		_checkSets.erase(ite);

		auto listIte = std::find(_tables.begin(), _tables.end(), table);
		if (listIte != _tables.end()) {
			_tables.erase(listIte);
		}

		table->Clear();
	}
}

void TableContainer::RemoveAll() {
	Clear();
	_checkSets.clear();
	_tables.clear();
}
