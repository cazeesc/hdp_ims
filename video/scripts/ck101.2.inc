<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$itemNo = 0;
		$siteURLprefix = 'http://video.ck101.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, 'title="', '"'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = trim(str_between($video, 'href="', '"'));
			// Fix the link
			$l = explode('/', $link);
			if (strcmp($l[count($l)-1], 'lists') == 0)
				$link .= '/1';
			if (strpos($link, $siteURLprefix) === false)
				$link = $siteURLprefix . $link;
			$link = str_replace('/tvshow',	'/tv/lists/2', $link);
			$link = str_replace('/arts',	'/tv/lists/1', $link);
			$link = str_replace('/comic',	'/tv/lists/3', $link);
			$image = '';
			$note  = '';
			$extra = $itemNo;
			$itemNo ++;

			if ($itemNo <= 3) {
				$queryLevel = '.type_1.query';
				$pageStart = 1;

				$titleOrig = $title;
				$linkOrig = $link;

				// 人氣排行
				$title = $titleOrig . ' [排序: 人氣排行]';
				$link = $linkOrig . '/hot';
				include('04_query.inc');

				// 最新上架
				$title = $titleOrig . ' [排序: 最新上架]';
				$link = $linkOrig . '/create';
				include('04_query.inc');
			}
			else {
				$queryLevel = '.type_2.query';
				$pageStart = 0;
				include('04_query.inc');
			}
		}
	}
?>
</channel>
