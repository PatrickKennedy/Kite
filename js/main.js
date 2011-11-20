jQuery(document).ready(function(){
	var last_mouse_pos = [0,0],
			drag_position,
			dragging,
			resize_original,
			resizing;

//    jQuery(document.body).on({
//        mouseup: function(e){
//            dragging = false;
//            if (resizing){
//                resizing = false;
//                //jQuery("#edging").css('margin', 0);
//            }
//        },

//        mousemove: function(e){
//            // Handle a bug where movement of the window under the cursor
//            // triggers a mousemove event.
//            if (last_mouse_pos[0] == e.screenX && last_mouse_pos[1] == e.screenY)
//                    return true
//            if (dragging) {
//                var w   = Titanium.UI.currentWindow,
//                    edging 	= jQuery("#edging"),
//                    new_x 	= e.screenX - drag_position.x,
//                    new_y 	= e.screenY - drag_position.y,
//                    edge_offset = edging.offset(),
//                    edge_corner = {
//                            left: 	new_x + edge_offset.left,
//                            top: 	new_y + edge_offset.top,
//                            right: 	new_x + w.width - edge_offset.left,
//                            bottom: new_y + w.height - edge_offset.top
//                    };
//                Titanium.API.info("window pos: "+window.screenX);
//                if (edge_corner.left < 0 && edge_corner.left > -25) {
//                        new_x = -edge_offset.left;
//                } else if (edge_corner.right > screen.width && edge_corner.right < screen.width+25) {
//                        new_x = edge_offset.right;
//                }
//                if (edge_corner.top < 0 && edge_corner.top > -25) {
//                        new_y = -edge_offset.top;
//                } else if (edge_corner.bottom > screen.height && edge_corner.bottom < screen.height+25) {
//                        new_y = edge_offset.bottom;
//                }

//                w.x = new_x;
//                w.y = new_y;
//                //if (Snapping.snapped(w)) {

//                //} else {

//                //}
//            } else if (resizing) {
//                var w = Titanium.UI.currentWindow,
//                        p = drag_position;
//                w.width = resize_original.x + (e.screenX - p.x);
//                w.height = resize_original.y + (e.screenY - p.y);
//            }
//            last_mouse_pos = [e.screenX, e.screenY]
//        }
//    });

	jQuery("#title-bar").on({
		mousedown: function(e){
			if (e.button !== undefined && e.button == 0) {
				window_manager.start_drag();
			}
		}
	});

	jQuery("#resizer").on({
		mousedown: function(e){
			e.stopPropagation();
			window_manager.start_resize();
		}
	});

	jQuery("#minimize").on("click", function() {
		window_manager.minimize();
	});
	jQuery("#close").on("click", function() {
		window_manager.close();
	});

//    jQuery("#new-window").on("click", function() {
//         Titanium.UI.createWindow("app://index.html");
//    });

});
