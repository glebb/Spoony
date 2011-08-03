require 'rubygems'
require 'tdriver'
include TDriverVerify
require 'rspec'

#Before do
#After do

$sut = TDriver.connect_sut( :Id => 'sut_qt')
#$app = $sut.run( :name => "/Users/antti/tinkerin/snoopy/debug/Snoopy.app/Contents/MacOS/Snoopy", :arguments => "-testability")
$app = $sut.run( :name => "c:/work/snoopy/debug/Snoopy", :arguments => "-testability")
#$app = $sut.run( :name => "/home/ubuntu/projects/snoopy/debug/Snoopy", :arguments => "-testability")

at_exit do
  $sut.application.close
end

Given /^the game is running$/ do
  $app.fixture('poonsy', 'start')
end

When /^the level nr is (\d+)$/ do |arg1|
  $app.fixture('poonsy', 'changeLevel', {:level => arg1.to_s()})
end

Then /^I should see levelname: "([^"]*)"$/ do |arg1|
  $temp = $app.fixture('poonsy', 'getLevelName')
  $temp.should == arg1
end

When /^Snoopy has not died$/ do
  #do nothing
end

Then /^lives should be "([^"]*)"$/ do |arg1|
  $temp = $app.fixture('poonsy', 'getLives')
  $temp.should == arg1
end

When /^Snoopy dies (\d+) times$/ do |arg1|
  for i in 1..arg1.to_i
    $app.fixture('poonsy', 'die')
  end
end

Given /^the game starts$/ do
    $app.fixture('poonsy', 'startupScreen')
end

When /^I do nothing$/ do
  #do nothing
end

Then /^I should see startupscreen with text SNOOPY$/ do
  verify(){$app.QDeclarativeText( :text => 'SNOOPY')}
end

When /^I press "([^"]*)"$/ do |arg1|
  $sut.press_key(("k"+arg1).to_sym)
end

Then /^the game screen is shown$/ do
  #do nothing
end
