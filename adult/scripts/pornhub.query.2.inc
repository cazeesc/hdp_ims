<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<var class="duration">', '</var>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, '<var class="added">', '</var>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<span class="views"><var>', '</var>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, '<div class="value">', '</div>'));

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>