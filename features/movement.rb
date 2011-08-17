When /^I keep right arrow pressed down for a while$/ do
  $app.QGraphicsView( :name => '' ).SnoopySprite( :name => 'SnoopySprite' ).press_key(:kRight)
  sleep 0.5
  $app.QGraphicsView( :name => '' ).SnoopySprite( :name => 'SnoopySprite' ).press_key(MobyCommand::KeySequence.new( :kRight, :KeyUp ))
end

Then /^character should be moving right$/ do
  $position.should < $app.QGraphicsView( :name => '' ).SnoopySprite.attribute("x").to_i
end

Given /^the character is on on position "([^"]*)"$/ do |arg1|
  $app.QGraphicsView( :name => '' ).SnoopySprite( :name => 'SnoopySprite' ).set_attribute("x", arg1)
  $position = arg1.to_i
end

When /^I keep left arrow pressed down for a while$/ do
$app.QGraphicsView( :name => '' ).SnoopySprite( :name => 'SnoopySprite' ).press_key(:kLeft)
sleep 0.5
$app.QGraphicsView( :name => '' ).SnoopySprite( :name => 'SnoopySprite' ).press_key(MobyCommand::KeySequence.new( :kLeft, :KeyUp ))
end

Then /^character should be moving left$/ do
  $position.should > $app.QGraphicsView( :name => '' ).SnoopySprite.attribute("x").to_i
end

#TODO: Exercise 4, copy stubs here and implement
