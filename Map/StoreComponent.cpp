#include "StoreComponent.h"
#include "PlayerManager.h"
void StoreComponent::init() {
    myPlayer = PlayerManager.getInstance().getPlayer(0);
    store = Store::create(myPlayer->myStore);  // Assuming myPlayer is a global or accessible variable
}

void StoreComponent::update() {
    // outlook update for store
}

void StoreComponent::draw() {
    store->draw();
}

StoreComponent::~StoreComponent() {
    if (store) {
        delete store;
    }
}
