Feature: Startup Screen
    As a Player
    I want to see a startup screen when I start the game
    So I know when game has loaded and I can start to play
    
    Background:
        Given the game starts

    #TODO: Exercise 3
    Scenario: Startup screen with title
        When I do nothing
        Then I should see startupscreen with text SNOOPY

    Scenario Outline: Start playing by any key
        When I press <key>
        Then the game screen is shown
        
        Examples:
            | key |
            | "A"   |            
            | "1"   |
            | "Enter"  |
            | "Space"  |
            | "Right"  |
