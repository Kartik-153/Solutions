#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val) : m_valBegin(val) {}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
// INSERT YOUR SOLUTION HERE
		if(!(keyBegin < keyEnd))      // finds the bound condition
			return;
		
		auto itBegin = m_map.lower_bound(keyBegin); // Gives the iterator to just previous key value(keyBegin).
		auto itEnd = m_map.upper_bound(keyEnd);     // Gives the iterator to the first element greater than the values given(keyEnd)

		if(itBegin == m_map.begin()) {  
			m_valBegin = val;
		} else {
			--itBegin;
		}
		if((itBegin)->second == val) {
			return;
		}
		m_map.erase(itBegin, itEnd);
		m_map[keyBegin] = val;
		m_map[keyEnd] = itBegin->second;
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

	
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.