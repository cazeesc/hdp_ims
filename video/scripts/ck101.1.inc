<?php
	$link = $search = 'http://video.ck101.com';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlVideos = str_between($html, '<div class="menu"', '</div>');

	$videos = explode('</a></li>', $htmlVideos);
	unset($videos[count($videos)-1]);	// Suffix
	unset($videos[count($videos)-1]);	// ��L
	unset($videos[count($videos)-1]);	// ���H�u��
	unset($videos[count($videos)-1]);	// ���H�v��
	unset($videos[count($videos)-1]);	// ���H�ʺ�
	unset($videos[0]);	// Prefix + ����
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>