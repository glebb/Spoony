Feature: Game Screen
    As a Player
    I want to see basic information on my game screen
    So I can keep track on my progress

    The gamescreen contains information about the current level
    and the player stats (like lives)

    Background:
        Given the game is running

    Scenario Outline: Level name
        When the level nr is <nr>
        Then I should see levelname: <levelname>
        
        Examples:
        | nr | levelname |
        | 1  | "LOOK OUT spoony" |
        | 2  | "JUMPING spoony" |
        | 3  | "WAS THIS IN THE ORIGINAL?" |
        | 4  | "UNNAMED" |
        
    Scenario: Lives without deaths
        When spoony has not died
        Then lives should be "3"

    #TODO: Exercise 4
    Scenario Outline: Lives reduce with death
        When spoony dies <nr> times
        Then lives should be <lives>
        
        Examples:
        | nr | lives |
        | 1  |   "2"   |
        | 2  |   "1"   |
        | 3  |   "3"   |        
