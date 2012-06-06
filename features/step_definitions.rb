require 'rubygems'
require 'tdriver'
include TDriverVerify
require 'rspec'

#Before do
#After do

$sut = TDriver.connect_sut( :Id => 'sut_qt')

if RUBY_PLATFORM.downcase.include?("darwin")
  puts Dir.pwd
  $app = $sut.run( :name => Dir.pwd + "/debug/spoony.app/Contents/MacOS/spoony", :arguments => "-testability")
else
  $app = $sut.run( :name => Dir.pwd + "/debug/spoony", :arguments => "-testability")
end

at_exit do
  $sut.application.close
end

Given /^the game is running$/ do
  $app.fixture('spoony', 'start')
  $lives_in_the_beginning = $app.fixture('spoony', 'getLives')
end

Given /^the game starts$/ do
    $app.fixture('spoony', 'startupScreen')
end

When /^I do nothing$/ do
  #do nothing
end

#TODO: Exercise 4
Then /^I should see startupscreen with text spoony$/ do
  $app.QDeclarativeText(:name => 'title').attribute("text").should == "spoony"
end

When /^I press "([^"]*)"$/ do |arg1|
  $sut.press_key(("k"+arg1).to_sym)
end

Then /^the game screen is shown$/ do
  spoony = $app.QGraphicsView( :name => '' ).spoonySprite
  spoony.should_not be_nil
end

