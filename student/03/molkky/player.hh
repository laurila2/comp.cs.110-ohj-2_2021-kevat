#ifndef PLAYER_HH
#define PLAYER_HH

#include <string>

class Player
{
public:
    Player(const std::string& name);
    const std::string& get_name();
    bool has_won();
    int get_points();
    void add_points(int amount);
private:
    const std::string NAME_;
    int points_;

};

#endif // PLAYER_HH
