Feature: Game Screen
    As a Player
    I want to see basic information on my game screen
    So I can keep track on my progress
        
    Background:
        Given the game is running

    Scenario Outline: Level name
        When the level nr is <nr>
        Then I should see levelname: <levelname>
        
        Examples:
        | nr | levelname |
        | 1  | "LOOK OUT SNOOPY" |
        | 2  | "JUMPING SNOOPY" |
        | 3  | "WAS THIS IN THE ORIGINAL?" |
        | 4  | "UNNAMED" |
        
    Scenario: Lives without deaths
        When Snoopy has not died
        Then lives should be "3"

    Scenario Outline: Lives reduce with death
        When Snoopy dies <nr> times
        Then lives should be <lives>
        
        Examples:
        | nr | lives |
        | 1  |   "2"   |
        | 2  |   "1"   |
        | 3  |   "3"   |        