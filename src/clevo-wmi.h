#pragma once

static const char* clevo_event_guid = "ABBC0F6B-8EA1-11D1-00A0-C90629100000";
static const char* clevo_email_guid = "ABBC0F6C-8EA1-11D1-00A0-C90629100000";
static const char* clevo_get_guid   = "ABBC0F6D-8EA1-11D1-00A0-C90629100000";

typedef enum
{
	LEFT_REGION		=	0xF0,
	CENTER_REGION	=	0xF1,
	RIGHT_REGION	=	0xF2,
	EXTRA_REGION	=	0xF3
} kb_region_t;

typedef enum
{
	LED_CUSTOM			=	0x00000000,
	LED_BREATHE			=	0x1002A000,
	LED_CYCLE			=	0x33010000,
	LED_DANCE			=	0x80000000,
	LED_FLASH			=	0xA0000000,
	LED_RANDOM_COLOR	=	0x70000000,
	LED_TEMPO			=	0x90000000,
	LED_WAVE			=	0xB0000000
} kb_led_mode_t;

typedef enum
{
	GET_EVENT	=	0x01,
	GET_AP		=	0x46,
	SET_KB_LED	=	0x67
} clevo_method_id_t;

static const u8 kb_brightness_id = 0xF4;

// Methods for controlling the clevo led keyboard
static void kb_set_brightness(u8 brightness);
static void kb_set_state(u8 state);
static int	kb_set_mode(kb_led_mode_t mode);
static int 	kb_set_color(kb_region_t region, u32 color);