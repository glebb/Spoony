Feature: Basic movement
    As a Player
    I want to move the character
    So I'm able to play the game

    Background:
        Given the game is running


    Scenario: Moving right
        Given the character is on on position "50"
        When I keep right arrow pressed down for a while
        Then character should be moving right

    Scenario: Moving left
        Given the character is on on position "250"
        When I keep left arrow pressed down for a while
        Then character should be moving left
