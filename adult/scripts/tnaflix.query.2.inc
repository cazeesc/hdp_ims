<?php
	$siteURLprefix = 'http://www.tnaflix.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ');"  src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, 'screen">', '</span>'));
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>