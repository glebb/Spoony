When /^the level nr is (\d+)$/ do |arg1|
  $app.fixture('poonsy', 'changeLevel', {:level => arg1.to_s()})
end

Then /^I should see levelname: "([^"]*)"$/ do |arg1|
  $temp = $app.fixture('poonsy', 'getLevelName')
  $temp.should == arg1
end

When /^Snoopy has not died$/ do
  $lives_in_the_beginning.should == $app.fixture('poonsy', 'getLives')
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
