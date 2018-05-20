#pragma once
#include <map>

namespace MeliosChat::MapUtilities
{
	template<class K, class V>
	V& Add(std::map<K, V>& map, const K& key, V&& value)
	{
		return map.insert(std::map<K, V>::value_type(key, value)).first->second;
	}
}
