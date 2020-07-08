/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <string>
#include <unordered_map>

namespace GCL {
namespace Serialization {

class ITable {
public:
	virtual ~ITable() {}
	virtual void Load() = 0;
	virtual void Reload() = 0;
	virtual void Clear() = 0;
};

template <typename TClass, typename TElement, typename TKey = std::string>
class TableBase : public ITable {
public:
	static TClass* GetInstance() {
		static TClass _ins;
		return &_ins;
	}

public:
	virtual void Load() = 0;

	virtual void Reload() {
		Clear();
		Load();
	}

	virtual void Clear() {
		for (auto& pair : _map) {
			delete pair.second;
		}
		_map.clear();
	}

	virtual TElement* GetElement(const TKey& key) const {
		auto ite = _map.find(key);
		if (ite != _map.end()) {
			return ite->second;
		}
		return nullptr;
	}

	const std::unordered_map<TKey, TElement*>& GetTableMap() const { return _map; }

	static TElement* CreateElement() {
		return new TElement();
	}

protected:
	void InsertElement(const TKey& key, TElement* element) {
		_map.emplace(key, element);
	}
	void AssignMap(std::unordered_map<TKey, TElement*>&& dataMap) {
		Clear();
		_map = dataMap;
	}

private:
	std::unordered_map<TKey, TElement*> _map;
};

} // namespace Serialization
} // namespace GCL