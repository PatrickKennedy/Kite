jQuery(document).ready(function(){
	var mouse_down = 0;

	jQuery("#title-bar").on({
		mousedown: function(e) {
			if (e.button !== undefined && e.button === 0)
				++mouse_down;
		},

		mousemove: function(e){
			if (mouse_down)
				window_manager.dragging = true;
		},

		mouseup: function (e) {
			if (e.button !== undefined && e.button === 0)
				--mouse_down;
			if (!window_manager.dragging) {
				window_manager.toggle_fold();
			}
		}
	});

	jQuery("#resizer").on({
		mousedown: function(e){
			e.stopPropagation();
			window_manager.resizing = true;
		}
	});

	jQuery("#minimize").on("click", function(e) {
		window_manager.minimize();
		e.stopPropagation();
	});

	jQuery("#close").on("click", function(e) {
		window_manager.close();
		e.stopPropagation();
	});
});
