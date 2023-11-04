
template<class T>
bool sendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea)
{
    Sea::Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea, T::getName());
    auto missile = std::make_shared<T>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}
