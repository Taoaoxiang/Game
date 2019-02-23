# CMakeList.txt : CMake project for Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0.2)

project(Blackjack)



# Add source to this project's executable.
add_executable (Blackjack 
	"Blackjack.cpp" "card.cpp" "deck.cpp" 
	"dealer.cpp" "player.cpp" "table.cpp"
	"rule.cpp")

# TODO: Add tests and install targets if needed.
