//
// Created by Дима Щипицын on 29/10/2021.
//

#ifndef ENGINE_RESOURCEHOLDER_H
#define ENGINE_RESOURCEHOLDER_H

#include <string>
#include <map>
#include "Headers.hpp"

template <typename Resource, typename Identifier>
class ResourceHolder {
public:
    void            load(Identifier id, const std::string& filename) {
        std::unique_ptr<Resource> resource(new Resource());
        if (!resource->loadFromFile(filename))
            throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
        auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
        assert(inserted.second);
    }
    Resource&       get(Identifier id) {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());
        return *found->second;
    }
    const Resource& get(Identifier id) const {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());
        return *found->second;
    }

private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};


#endif //ENGINE_RESOURCEHOLDER_H
