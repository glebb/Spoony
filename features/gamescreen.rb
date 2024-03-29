When /^the level nr is (\d+)$/ do |arg1|
  $app.fixture('spoony', 'changeLevel', {:level => arg1.to_s()})
end

Then /^I should see levelname: "([^"]*)"$/ do |arg1|
  $temp = $app.fixture('spoony', 'getLevelName')
  $temp.should == arg1
end

When /^spoony has not died$/ do
  $lives_in_the_beginning.should == $app.fixture('spoony', 'getLives')
end

Then /^lives should be "([^"]*)"$/ do |arg1|
  $temp = $app.fixture('spoony', 'getLives')
  $temp.should == arg1
end

When /^spoony dies (\d+) times$/ do |arg1|
  for i in 1..arg1.to_i
    $app.fixture('spoony', 'die')
  end
end
