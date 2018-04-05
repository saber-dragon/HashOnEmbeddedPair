Hash on Embedded Pair
=====================
[![Build Status](https://travis-ci.org/saber-dragon/HashOnEmbeddedPair.svg?branch=master)](https://travis-ci.org/saber-dragon/HashOnEmbeddedPair)

This repo provides you a simple method to apply `hash` on a `std::pair`, 
which might be an embedded pair, _e.g._, `std::pair<std::pair<int, double>, std::string>`.


## Example

```C++
auto p = make_pair(10, 20);
unordered_map<pair<int, int>, bool, PairHash> mapOfSimplePair;
mapOfSimplePair.insert({p, true});
```


