#include "ModLoader.hpp"
#include <Windows.h>
#include <iostream>

#define SOL_ALL_SAFETIES_ON 1
#include "..\sol.hpp"

ModLoader::ModLoader() {}

ModLoader::~ModLoader() {
    for (int i = 0; i < m_mods.size(); i++) {
        Mod* mod = m_mods[i];
        m_mods.erase(m_mods.begin() + i);
        delete mod;
    }
}

void ModLoader::loadMod(const std::string& name, const std::string& path) {
    Mod* mod = new Mod(name, path);
    m_mods.push_back(mod);
}

std::vector<Mod*> ModLoader::getMods() {
    return m_mods;
}