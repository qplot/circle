$(function(){
var radius = 240;
var fields = $('.fieldc'), container = $('#container'), width = container.width(), height = container.height();
var angle = 4.714, step = (2*Math.PI) / fields.length;
fields.each(function() {
    var x = Math.round(width/2 + radius * Math.cos(angle) - $(this).width()/2);
    var y = Math.round(height/2 + radius * Math.sin(angle) - $(this).height()/2);
    if(window.console) {
        console.log($(this).text(), x, y);
    }
    $(this).css({
        left: x + 'px',
        top: y + 'px'
    });
    angle += step;
});
});//]]>  