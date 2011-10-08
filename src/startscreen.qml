import Qt 4.7

Item
{
    id: item
    width: 840; height: 480
    Rectangle
    {
        objectName: "frame"
        id: page
        width: 840; height: 480
        color: "lightgray"
    }

    Text
    {
        id: title
        objectName: "title"
        text: "SNOOPY"
        anchors.verticalCenter: page.verticalCenter
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 80; font.bold: true
    }

    Text
    {
        id: anykey
        objectName: "anykey"
        anchors.top: title.bottom
        anchors.horizontalCenter: page.horizontalCenter
        text: "HIT ANY KEY TO START"
        font.pointSize: 20;
    }

    Text
    {
        id: info
        objectName: "info"
        y: 10
        anchors.horizontalCenter: page.horizontalCenter
        text: "Tribute to classic C64 game Snoopy by C. Kramer"
        font.pointSize: 16;
    }

    focus: true
    Keys.onPressed: {
        event.accepted = true;
        Game.start();
    }
}
