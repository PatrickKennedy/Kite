
var Snapping = {
	snap_to_side: function() {
		var w = Titanium.UI.currentWindow,
			edging = jQuery("#edging"),
			edge_offset = edging.offset(),
			edge_corner = [w.x + edge_offset.left, w.y + edge_offset.top];
		Titanium.API.debug("position: "+ edge_corner);
		if (Math.abs(edge_corner[0]) < 25) {
			w.x = -edge_offset.left;
		}
	}
};