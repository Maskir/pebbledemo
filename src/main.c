#include <pebble.h>

Window *my_window;
TextLayer *text_layer;

void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Select");
}

void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Up");
}

void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Down");
}

void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 20 } });
  text_layer_set_text(text_layer, "Press a button");
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

void window_unload(Window *window) {
  text_layer_destroy(text_layer);
}

void handle_init(void) {

	my_window = window_create();
  	window_set_click_config_provider(my_window, click_config_provider);
  	window_set_window_handlers(my_window, (WindowHandlers) {
    	.load = window_load,
    	.unload = window_unload,
  });
 	window_stack_push(my_window, true);
	window_set_background_color(my_window, GColorBlack);

	//text_layer = text_layer_create(GRect(0, 0, 144, 20));	
}

void handle_deinit(void) {
	text_layer_destroy(text_layer);
	window_destroy(my_window);
}

int main(void) {
	handle_init();
	app_event_loop();
	handle_deinit();
}
